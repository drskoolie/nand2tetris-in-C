import os
import json

project_root = '/home/drskoolie/github/nand2tetris/'
src_path = os.path.join(project_root, 'src')
obj_path = os.path.join(project_root, 'obj')

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

with open(os.path.join(project_root, 'compile_commands.json'), 'w') as f:
    json.dump(commands, f, indent=4)

