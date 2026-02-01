project(
  'http-mt',
  'c',
  default_options: [
    'c_std=gnu23',
    'warning_level=3',
  ],
)

sources = []

external_deps = [dependency('threads')]

executable('http-mt', sources, dependencies: external_deps)
