{
  description = "42 DevShell";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs {
          inherit system;
        };
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            gcc
            gnumake
            valgrind
            gdb
	    norminette
	    clang
          ];

          shellHook = ''
            echo "Welcome to the 42 devShell"
            echo ""
            echo "Installed:"
	    echo " >> gcc: $(gcc --version | head -n 1)"
	    echo " >> make: $(make --version | head -n 1)"
            echo " >> valgrind: $(valgrind --version | head -n 1)"
            echo " >> gdb: $(gdb --version | head -n 1)"
            echo " >> norminette: $(norminette --version | head -n 1)"
            echo " >> clang: $(clang --version | head -n 1)"
          '';
        };
      }
    );
}

