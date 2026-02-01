{pkgs, stdenv, lib, mesonBuildType?"debug", ...}: 
  let 
    buildDeps = with pkgs; [gcc meson ninja pkg-config];

    fs = lib.fileset;
    sourceFiles = fs.difference
      (fs.gitTracked ./.)
      (fs.fileFilter (file: file.hasExt "nix") ./.);
  in
  fs.trace sourceFiles

  stdenv.mkDerivation {
    pname = "http-mt"; 
    version = "0.1.0";

    src = fs.toSource {
      root = ./.;
      fileset = sourceFiles;
    };
    
    nativeBuildInputs = buildDeps;

    mesonFlags = [
      "-Dbuildtype=${mesonBuildType}"
      "-Ddefault_library=static"
    ];
  } 
