import os
import subprocess
import re


def run_customasm():
    result = subprocess.run([f'./customasm/customasm', '-p', f'./customasm/decoder_test.asm', '-f', 'annotated,base:2,group:32'], capture_output=True, text=True)
    if result.returncode == 0:
        output_lines = result.stdout.splitlines()
        return output_lines
    else:
        print(f"Error: {result.stderr}")
        return []

def generate_decoder_test(bin, asm):
    result = subprocess.run([f'./build/decoder_test', f'{bin}', f'{asm}'], capture_output=True, text=True)
    if result.returncode == 0:
        output_lines = result.stdout.splitlines()
        return output_lines
    else:
        print(f"Error: {result.stdout}")
        return []
        
ls_output = run_customasm()
pattern = r'.*([01]{32}).*; *(.*)'

for line in ls_output:
    match = re.match(pattern, line)
    if match:
        bin = match.group(1)
        annotation = match.group(2);
        # print(f'{bin} {annotation}')
        test_lines = generate_decoder_test(bin, annotation)
        for t in test_lines:
            print(t)