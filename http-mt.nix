{pkgs, stdenv, lib, mesonBuildType?"debug", ...}: 
  let 
    buildDeps = with pkgs; [meson ninja pkg-config];

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
    
    inherit mesonBuildType;

    nativeBuildInputs = buildDeps;

    mesonFlags = [
      "-Ddefault_library=static"
    ];

    meta = {
      description = "A simple multi-threaded HTTP server written in C";
      homepage = "https://github.com/AntCursor/http-mt";
      license = lib.licenses.agpl3Only;
      maintainers = with lib.maintainers; [ antcursor ];
      mainProgram = "http-mt";
    };
  } 
