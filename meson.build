project(
  'http-mt',
  'c',
  version: '0.1.0',
  default_options: [
    'c_std=gnu23',
    'warning_level=3',
  ],
)

sources = files('src/main.c')

include_dirs = include_directories('include')

external_deps = [dependency('threads')]

executable(
  'http-mt',
  sources,
  dependencies: external_deps,
  include_directories: include_dirs,
  install: true,
)
