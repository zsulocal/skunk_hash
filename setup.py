from distutils.core import setup, Extension

Skunk_Hash_module = Extension('Skunk_Hash',
                                 sources = ['skunkhashmodule.c',
                                            'skunkhash.c',
                                            'sha3/gost.c',
                                            'sha3/skein.c',
                                            'sha3/cubehash.c',
                                            'sha3/fugue.c'],
                               include_dirs=['.', './sha3'])

setup (name = 'Skunk_Hash',
       version = '1.4',
       description = 'Binding for SkunkHash proof of work hashing.',
       ext_modules = [Skunk_Hash_module])
