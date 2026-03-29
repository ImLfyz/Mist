# Mist
Simple x86_64 operation system

## Attention
DO NOT start this on real PC. It made by junior for quemu

## Get started
1. Clone this to your PC:
```
git clone https://github.com/L-fyz/Mist.git ~/Mist
```
2. Compile this:
```
cd ~/Mist && make
```
3. Start with qemu:
```
qemu-system-x86_64 -drive format=raw,file=os.img -d int,cpu_reset -no-reboot
```

## Todo:
1. Keyboard driver
2. Command line
3. Command line parsing
4. Some utils
5. (Maybe) VGA driver
