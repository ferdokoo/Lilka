import os
import re

# Configuration
PREFIX = "gb_"
HEADER_EXTENSIONS = ('.h', '.hpp')
SOURCE_EXTENSIONS = ('.c', '.cpp', '.h', '.hpp')

# Regex patterns
FUNC_DECL_PATTERN = r'\b([a-zA-Z_][a-zA-Z_0-9]*)\s*\([^)]*\)\s*;'
FUNC_DEF_PATTERN = r'\b([a-zA-Z_][a-zA-Z_0-9]*)\s*\([^)]*\)\s*\{'
FUNC_CALL_DEF_PATTERN = r'\b{func}\b(?=\s*\()'

def find_all_files(folder_path, extensions):
    """Find all files with the specified extensions in the folder and subfolders."""
    files = []
    for root, _, file_list in os.walk(folder_path):
        for file in file_list:
            if file.endswith(extensions):
                files.append(os.path.join(root, file))
    return files

def find_functions(files, pattern):
    """Find all functions matching the given pattern in the specified files."""
    functions = set()
    for file in files:
        print(f"Scanning file: {file}")
        with open(file, 'r') as f:
            content = f.read()
            matches = re.findall(pattern, content)
            functions.update(matches)
        print(matches)
    return list(functions)

def update_files(files, functions, prefix):
    """Update function declarations, definitions, and calls in the specified files."""
    for file in files:
        print(f"Updating file: {file}")
        try:
            with open(file, 'r') as f:
                content = f.read()

            for func in functions:
                if not func.startswith(prefix):
                    # Update function calls
                    call_pattern = rf'\b{func}\b(?=\s*\()'
                    content = re.sub(call_pattern, f"{prefix}{func}", content)
                    
                    # Update function definitions and declarations
                    decl_def_pattern = rf'\b{func}\s*\('
                    content = re.sub(decl_def_pattern, f"{prefix}{func}(", content)

            with open(file, 'w') as f:
                f.write(content)

        except Exception as e:
            print(f"Error processing file {file}: {e}")

if __name__ == "__main__":
    folder_path = os.getcwd()

    # Step 1: Automatically find all header and source files
    print("Finding all header and source files...")
    header_files = find_all_files(folder_path, HEADER_EXTENSIONS)
    source_files = find_all_files(folder_path, SOURCE_EXTENSIONS)
    print(f"Header files found: {header_files}")
    print(f"Source files found: {source_files}")

    # Step 2: Find all function declarations and definitions
    print("Scanning header files for function declarations...")
    declared_functions = find_functions(header_files, FUNC_DECL_PATTERN)
    # print("Scanning source files for function definitions...")
    # defined_functions = find_functions(source_files, FUNC_DEF_PATTERN)

    # Combine all unique functions
    all_functions = set(declared_functions)

    # Step 3: Update all files
    print("Updating files with prefixed function names...")
    all_files = header_files + source_files
    update_files(all_files, all_functions, PREFIX)
    print("Update complete.")