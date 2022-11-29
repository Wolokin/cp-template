P="$HOME/.config/online-judge-tools"
T="$P/templates"
mkdir -p $T
ln -f prepare.config.toml $P
for F in template.cpp debug.h; do
    ln -sf ../$F $T
done
