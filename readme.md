# Ubuntu WSL

### in annepro2_qmk
```bash
make annepro2/c18:rcw
```

### in annepro2_shine
```bash
make C18
```

### in annepro2_tools/target/release/
```bash
cp /mnt/c/Users/Day/annepro2_qmk/annepro2_qmk/.build/annepro2_c18_rcw.bin /mnt/c/Users/Day/annepro2_qmk/annepro2_tools/target/release/
```

------------

```bash
cp /mnt/c/Users/Day/annepro2_qmk/annepro2_shine/build/annepro2-shine-C18.bin /mnt/c/Users/Day/annepro2_qmk/annepro2_tools/target/release/
```

------------


# PowerShell
### in annepro2_tools/target/release/

------------

```bash
./annepro2_tools annepro2_c18_rcw.bin
```

------------

```bash
./annepro2_tools --boot -t led annepro2-shine-C18.bin
```
