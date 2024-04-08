import glob
import os
import shutil
import subprocess
import sys

class CompileC:
    def __init__(self):
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

        self.flags = self.debug_flags + self.std_flags + self.include_flags + self.warnings_flags

    def _run_command(self, command):
        try:
            subprocess.run(command, check=True, capture_output=False, text=True)
        except subprocess.CalledProcessError:
            print(f"Failed to run {command}")

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
            elif os.path.isdir(file_path):
                shutil.rmtree(file_path)

        for file_name in os.listdir(self.obj_dir):
            file_path = os.path.join(self.obj_dir, file_name)

            if os.path.isfile(file_path) or os.path.islink(file_path):
                os.remove(file_path)
            elif os.path.isdir(file_path):
                shutil.rmtree(file_path)


def compile():
    cc = CompileC()

    cc.compile_sources()
    cc.link_sources()
    cc.run_executable()

def test():
    cc = CompileC()

    cc.compile_tests()
    cc.link_tests()
    cc.run_tests()

def clean():
    cc = CompileC()

    cc.clean()

sys.argv = [1, 2]

if len(sys.argv) == 2:
    argument = sys.argv[1]
    clean()
else:
    print("This script requires exactly one argument")
    sys.exit(1)

