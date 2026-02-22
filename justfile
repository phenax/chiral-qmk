
setup:
  #!/usr/bin/env sh
  if ! [ -L "/home/imsohexy/.local/share/qmk_firmware/keyboards/chiral" ]; then
    ln -s "$PWD" /home/imsohexy/.local/share/qmk_firmware/keyboards/chiral
  fi;

