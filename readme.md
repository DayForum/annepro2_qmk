# in annepro2_qmk
> make annepro2/c18:rcw

# in annepro2_shine
> make C18

# in annepro2_tools/target/release/
> cp /mnt/c/Users/Day/annepro2_qmk/annepro2_qmk/.build/annepro2_c18_rcw.bin /mnt/c/Users/Day/annepro2/annepro2_tools/target/release/annepro2_c18_rcw.bin

------------


> cp /mnt/c/Users/Day/annepro2_qmk/annepro2_shine/build/annepro2-shine-C18.bin /mnt/c/Users/Day/annepro2/annepro2_tools/target/release/annepro2-shine-C18.bin

## and
> annepro2_tools annepro2_c18_rcw.bin

------------

> annepro2_tools --boot -t led build/annepro2-shine-C18.bin
