{
  description = "get_next_line - 42 project development environment";


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
            llvm
          ];


          shellHook = ''
            echo "🔧 get_next_line development environment"
            echo "Available commands:"
            echo "  make          - Build get_next_line.a"
            echo "  make clean    - Remove object files"
            echo "  make fclean   - Remove all build artifacts"
            echo "  make re       - Rebuild from scratch"

            echo ""
            echo "Compiler: $(which gcc)"
            echo "Make: $(which make)"
          '';
        };
      }
    );
}

