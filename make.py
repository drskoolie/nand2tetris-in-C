import glob
import json
import os
import shutil
import subprocess
import sys

class CompileC:
    def __init__(self, warning = False):
        self.warning = warning

        self.src_dir = 'src'
        self.obj_dir = 'obj'
        self.bin_dir = 'bin'

        self.test_dir = 'tests'
        self.test_obj_dir = os.path.join(self.obj_dir, 'tests')
        self.test_bin_dir = os.path.join(self.bin_dir, 'tests')

        self.output_executable = os.path.join(self.bin_dir, 'nand')

        self.debug_flags = ['-g']
        self.std_flags = ['-std=c17']
        self.include_flags = ['-Iinclude', '-Iunity']
        self.warnings_flags = ['-Wall', '-Wextra']

        if self.warning:
            self.flags = self.debug_flags + self.std_flags + self.include_flags + self.warnings_flags
        else:
            self.flags = self.debug_flags + self.std_flags + self.include_flags


    def _run_command(self, command):
        try:
            subprocess.run(command, check=True, capture_output=False, text=True)
        except subprocess.CalledProcessError:
            print(f"Failed to run {command}")

    def _generate_json(self):
        project_root = '/home/drskoolie/github/nand2tetris/'
        src_path = os.path.join(project_root, 'src')
        test_path = os.path.join(project_root, 'tests')

        commands = []

        for file in os.listdir(src_path):
            if file.endswith('.c'):
                src_file = os.path.join('src', file)
                obj_file = os.path.join('obj', file.replace('.c', '.o'))
                command = {
                    "directory": project_root,
                    "command": f"gcc -Iinclude -c {src_file} -o {obj_file}",
                    "file": src_file
                }
                commands.append(command)

        for file in os.listdir(test_path):
            if file.endswith('.c'):
                src_file = os.path.join('src', file)
                obj_file = os.path.join('obj', file.replace('.c', '.o'))
                command = {
                    "directory": project_root,
                    "command": f"gcc -Iinclude -Iunity -c {src_file} -o {obj_file}",
                    "file": src_file
                }
                commands.append(command)

        with open(os.path.join(project_root, 'compile_commands.json'), 'w') as f:
            json.dump(commands, f, indent=4)


    def compile_file(self, src_path, obj_path):
        """Compile a single source file to an object file."""
        command = ['gcc'] + self.flags +  ['-c', src_path, '-o', obj_path]
        self._run_command(command)

    def compile_sources(self):
        if not os.path.exists(self.obj_dir):
            os.makedirs(self.obj_dir)

        src_paths = os.listdir(self.src_dir)
        obj_paths = [path.replace('.c', '.o') for path in src_paths]

        for src_path, obj_path in zip(src_paths, obj_paths):
            self.compile_file(os.path.join(self.src_dir, src_path),
                              os.path.join(self.obj_dir, obj_path))

    def compile_tests(self):
        if not os.path.exists(self.test_obj_dir):
            os.makedirs(self.test_obj_dir)

        test_paths = os.listdir(self.test_dir)
        test_obj_paths = [path.replace('.c', '.o') for path in test_paths]

        for test_path, test_obj_path in zip(test_paths, test_obj_paths):
            if test_path != "archive":
                self.compile_file(os.path.join(self.test_dir, test_path),
                                  os.path.join(self.test_obj_dir, test_obj_path))

    def link_sources(self):
        if not os.path.exists(self.bin_dir):
            os.makedirs(self.bin_dir)

        obj_files = glob.glob(self.obj_dir + '/*.o')
        command = ['gcc', '-o', self.output_executable] + obj_files
        self._run_command(command)

    def link_tests(self):
        if not os.path.exists(self.test_bin_dir):
            os.makedirs(self.test_bin_dir)

        obj_files = glob.glob(self.obj_dir + '/*.o')
        if 'obj/main.o' in obj_files:
            obj_files.remove('obj/main.o')

        obj_test_files = glob.glob(self.test_obj_dir + '/*.o')

        for obj_test_file in obj_test_files:
            executable = obj_test_file.split('/')[-1].split('.o')[0]
            executable = os.path.join(self.test_bin_dir, executable)
            command = ['gcc'] + self.flags + ['-o', executable] + [obj_test_file] + obj_files + ['unity/unity.c']
            self._run_command(command)


    def run_executable(self):
        command = ['./' + self.output_executable]
        self._run_command(command)

    def run_tests(self):
        test_executables = os.listdir(self.test_bin_dir)
        test_executables = [os.path.join(self.test_bin_dir, test_executable) for test_executable in test_executables]
        for test_executable in test_executables:
            command = ['./' + test_executable]
            self._run_command(command)

    def clean(self):
        for file_name in os.listdir(self.bin_dir):
            file_path = os.path.join(self.bin_dir, file_name)

            if os.path.isfile(file_path) or os.path.islink(file_path):
                os.remove(file_path)
                print(f"Deleted: {file_path}")
            elif os.path.isdir(file_path):
                shutil.rmtree(file_path)
                print(f"Deleted: {file_path}")

        for file_name in os.listdir(self.obj_dir):
            file_path = os.path.join(self.obj_dir, file_name)

            if os.path.isfile(file_path) or os.path.islink(file_path):
                os.remove(file_path)
                print(f"Deleted: {file_path}")
            elif os.path.isdir(file_path):
                shutil.rmtree(file_path)
                print(f"Deleted: {file_path}")


def compile():
    cc = CompileC()

    cc._generate_json()
    cc.compile_sources()
    cc.link_sources()

def test():
    cc = CompileC()

    cc.compile_tests()
    cc.link_tests()
    cc.run_tests()

def clean():
    cc = CompileC()

    cc.clean()

def run():
    cc = CompileC()

    cc.run_executable()

def warning():
    cc = CompileC(warning = True)

    cc._generate_json()
    cc.compile_sources()
    cc.link_sources()

if len(sys.argv) == 2:
    argument = sys.argv[1]

    if argument == "compile":
        compile()
    elif argument == "clean":
        clean()
    elif argument == "test":
        test()
    elif argument == "run":
        run()
    elif argument == "warning":
        warning()
    else:
        print("Argument {argument} is not accepted")
        sys.exit(1)
else:
    print("This script requires exactly one argument")
    sys.exit(1)

