{
  description = "A little C number multitool";

  inputs = {
    nixpkgs.url = "https://channels.nixos.org/nixpkgs-unstable/nixexprs.tar.zst";
    systems.url = "github:nix-systems/x86_64-linux";
    flake-utils = {
      url = "github:numtide/flake-utils";
      inputs.systems.follows = "systems";
    };
  };

  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
      ...
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        pname = "c-number-multitool";
        version = "0.1.0";
        src = ./.;

        makeFlags = [ "LDFLAGS=-lm" ];

        nativeBuildInputs = with pkgs; [
          gdb
          pkg-config
        ];
      in
      {
        devShells.default = pkgs.mkShell {
          inherit nativeBuildInputs;

        };

        packages.default = pkgs.stdenv.mkDerivation {
          inherit
            nativeBuildInputs
            pname
            version
            makeFlags
            src
            ;
        };
      }
    );
}
