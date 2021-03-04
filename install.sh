#! /bin/sh

set -e



echo "=> Installing low batter alert app...\n"
sudo cp lowbtrapp.o /usr/local/bin/
sudo chmod +x /usr/local/bin/lowbtrapp.o

echo "=> Starting ...\n"
sudo cp lowbtrapp.sh /etc/init.d/
sudo cp -r lowbtrsounds/ /usr/share/sounds/
sudo chmod +x /etc/init.d/lowbtrapp.sh

sudo update-rc.d lowbtrapp.sh defaults
sudo /etc/init.d/lowbtrapp.sh start

echo "Low battery alert installed."
