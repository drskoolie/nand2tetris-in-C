import glob
import os
import subprocess
from pathlib import Path

class CompileC:
    def __init__(self):
        self.src_dir = 'src'
        self.obj_dir = 'obj'
        self.bin_dir = 'bin'
        self.test_dir = 'test'
        self.obj_test_dir = os.path.join('bin', 'tests')

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

        src_files = glob.glob(self.src_dir + '/*.c')
        obj_files = [file.replace('.c', '.o') for file in src_files]

        for src_file, obj_file in zip(src_files, obj_files):
            self.compile_file(src_file, obj_file)

    def compile_tests(self):
        if not os.path.exists(self.obj_test_dir):
            os.makedirs(self.obj_test_dir)

    def link_objects(self):
        if not os.path.exists(self.bin_dir):
            os.makedirs(self.bin_dir)

        obj_files = glob.glob(self.obj_dir + '/*.o')
        command = ['gcc', '-o', self.output_executable] + obj_files
        self._run_command(command)

    def run_program(self):
        command = ['./' + self.output_executable]
        self._run_command(command)


if __name__ == "__main__":
    cc = CompileC()
    cc.compile_sources()
    cc.link_objects()
    cc.run_program()
    cc.compile_tests()
    
