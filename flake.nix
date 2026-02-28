{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
      ...
    }:
    let
      shell =
        { pkgs }:
        pkgs.mkShell {
          buildInputs = with pkgs; [
            qmk
            dos2unix
            just
            clang-tools
            unixtools.xxd
            pkg-config
            xev
          ];
        };
    in
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        devShells.default = shell { inherit pkgs; };
      }
    );
}
