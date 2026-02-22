
setup:
  #!/usr/bin/env sh
  if ! [ -L "/home/imsohexy/.local/share/qmk_firmware/keyboards/chiral" ]; then
    ln -s "$PWD" /home/imsohexy/.local/share/qmk_firmware/keyboards/chiral
  fi;

compiledb:
  qmk compile --compiledb -kb chiral -km default
  cp "$QMK_HOME/compile_commands.json" .

build:
  mkdir -p ./build
  qmk compile -kb chiral -km default
  cp "$QMK_HOME"/.build/*.uf2 ./build/
  ls -l build/

