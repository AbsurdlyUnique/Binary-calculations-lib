# Project definition
project('text_to_binary', 'c',
        version: '1.0.0',
        default_options: ['warning_level=3', 'c_std=c11'])

# Compiler arguments for the shared library
lib_args = ['-DBUILDING_MESON_LIBRARY']

# Define the shared library
shared_lib = shared_library('text_to_binary_lib',  # Unique library name
                            'src/text_to_binary.c',  # Ensure this file exists
                            include_directories: include_directories('include'),
                            install: true,
                            c_args: lib_args)

# Define the test executable
executable('test_text_to_binary',  # Unique executable name
           'src/test_text_to_binary.c',  # Correct path for the test file
           include_directories: include_directories('include'),
           link_with: shared_lib)
