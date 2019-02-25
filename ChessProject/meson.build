project('chess', 'cpp')
sdl = dependency('SDL2')
sdl_image = dependency('SDL2_image')
shared = ['main.cpp', 'piece.cpp', 'chess.cpp', 'board.cpp', 'Graphic.cpp', 'loadsave.cpp']
executable('chess', shared, dependencies: [sdl, sdl_image])
