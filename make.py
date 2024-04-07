import glob
import os
import subprocess
from pathlib import Path

class CompileC:
    def __init__(self):
        self.src_dir = 'src'
        self.obj_dir = 'obj'

        self.exec = 'nand'

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

    def compile_source(self, src_path, obj_path):
        """Compile a single source file to an object file."""
        command = ['gcc'] + self.flags +  ['-c', src_path, '-o', obj_path]
        self._run_command(command)

    def compile_sources(self):
        self.get_source_files()
        for src_file, obj_file in zip(self.src_files, self.obj_files):
            self.compile_source(src_file, obj_file)

    def link_objects(self):
        pass


    def get_source_files(self):
        self.src_files = glob.glob(self.src_dir + '/*.c')
        self.obj_files = [file.replace('.c', '.o') for file in self.src_files]


if __name__ == "__main__":
    cc = CompileC()
    cc.compile_sources()
