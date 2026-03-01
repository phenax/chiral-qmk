
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
  cp "$QMK_HOME"/.build/chiral_default.uf2 ./build/
  ls -l build/

flash:
  #!/usr/bin/env sh
  mountpoints=$(lsblk -n -o NAME,MOUNTPOINT,TRAN \
    | awk '$2=="usb" {print $1}' \
    | xargs -i lsblk -n -o MOUNTPOINT /dev/{} \
    | sed '/^$/d');
  if [ -z "$mountpoints" ]; then
    echo "No connected devices" && exit 1;
  fi;
  selected=$(echo "$mountpoints" | fzf);
  if [ -z "$selected" ]; then exit 0; fi;
  cp build/chiral_default.uf2 /run/media/imsohexy/RPI-RP2/

