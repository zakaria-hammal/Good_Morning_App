#!/bin/sh

echo "Installation of Good Morning"

mkdir -p ~/.local/bin

gcc src/main.c -o ~/.local/bin/goodmorning $(pkg-config --cflags --libs libnotify glib-2.0)

chmod +x ~/.local/bin/goodmorning

mkdir -p ~/.config/systemd/user

echo "Your name :"
read name

SHELL_CONFIG=""
if [ -n "$BASH" ]; then
    SHELL_CONFIG="$HOME/.bashrc"
elif [ -n "$ZSH_VERSION" ]; then
    SHELL_CONFIG="$HOME/.zshrc"
else
    # Default to bashrc
    SHELL_CONFIG="$HOME/.bashrc"
fi

sed -i '/export GM_APP_USER=/d' ~/.bashrc
echo "export GM_APP_USER=\"$name\"" >> "$SHELL_CONFIG"

cp service/goodmorning.service ~/.config/systemd/user/

systemctl --user daemon-reload

systemctl --user enable --now goodmorning.service
