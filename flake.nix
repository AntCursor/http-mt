{
  description = "A simple multi-threaded HTTP server written in C";

  inputs = {
    flake-parts.url = "github:hercules-ci/flake-parts";
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = inputs@{ flake-parts, ... }:
    flake-parts.lib.mkFlake { inherit inputs; } {
      imports = [
      ];
      systems = [ "x86_64-linux" "aarch64-linux" "aarch64-darwin" "x86_64-darwin" ];
      perSystem = { config, self', inputs', pkgs, system, ... }: {

        # To call with 'nix build .'
        packages.http-mt = pkgs.callPackage ./http-mt.nix {};

        # To call with 'nix build'
        packages.default = self'.packages.http-mt;

        # To call with 'nix run .#http-mt'
        apps.http-mt = {
          type = "app";
          program = self'.packages.http-mt;
        };

        # To call with 'nix run'
        apps.default = self'.apps.http-mt;

      };
      flake = {
      };
    };
}
