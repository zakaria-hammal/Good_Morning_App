# Good Morning App

An application that greets you every day with a motivational quote

## ⚙️ Dependencies

You need the following packages:

- **libnotify** → desktop notifications (integrates with KDE Plasma notifications)  
- **systemd** → service manager  

### On Arch Linux / Manjaro

```bash
sudo pacman -S base-devel libnotify systemd
```

### On Debian / Ubuntu

```bash
sudo apt install build-essential libnotify-dev systemd
```

---

## 🔨 Installation

Clone the repo and install:

```bash
git clone https://github.com/zakaria-hammal/Good_Morning_App.git
cd Good_Morning_App

chmod +x install.sh
./install.sh
```

---

## 🖥️ KDE Plasma Notes

- Notifications appear in **Plasma’s native notification tray**.  
- You can control how they behave in:  
  `System Settings → Notifications → Prayer Timer` (after first run).  
- Make sure `plasmashell` is running (default in KDE sessions).  
