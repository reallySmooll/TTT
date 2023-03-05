project('tic-tac-toe', 'cpp',
  version : '1.0.0',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

# These arguments are only used to build the STATIC library
# not the executables that use the library.
lib_args = ['-DBUILDING_TIC_TAC_TOE']

sfml_all_dep = dependency('sfml-all')

TTT_lib_src = [ 'src/TTT_Window.cpp', 'src/TTT_Utils.cpp', 'src/TTT_Log.cpp' ]

TTT_lib = static_library('TTT', TTT_lib_src,
  dependencies : sfml_all_dep,
  install : true,
  cpp_args : lib_args,
  gnu_symbol_visibility : 'hidden',
)

sandbox = executable('Sandbox', 'sandbox/1.cpp',
  link_with : TTT_lib)

# Make this library usable as a Meson subproject.
ttt_dec_dep = declare_dependency(
  include_directories : include_directories('include/TTT'),
  link_with : TTT_lib)

# Make this library usable from the system's
# package manager.
install_headers('include/TTT/TTT.hpp', subdir : 'TTT')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : 'TTT',
  filebase : 'TTT',
  description : 'Small wrapper library for SFML.',
  subdirs : 'TTT',
  libraries : TTT_lib,
  version : '1.0.0',
  requires : 'sfml-all'
)
