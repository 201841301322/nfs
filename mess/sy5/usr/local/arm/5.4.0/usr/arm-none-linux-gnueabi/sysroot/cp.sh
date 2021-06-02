#!/bin/sh
for file in libc libcrypt libdl libm libpthread libresolv libutil
do
sudo cp lib/$file*.so /home/geclab/rootfs-6818/lib
sudo cp -d lib/$file.so.* /home/geclab/rootfs-6818/lib
done
sudo cp -d lib/ld*.so* /home/geclab/rootfs-6818/lib
sudo cp -d usr/lib/libstdc++.so* /home/geclab/rootfs-6818/lib
sudo cp -d lib/libgcc_s* /home/geclab/rootfs-6818/lib
sudo cp -d lib/libnss*.so* /home/geclab/rootfs-6818/lib
sudo cp -d lib/librt* /home/geclab/rootfs-6818/lib
sudo cp -d usr/lib/libjpeg.so* /home/geclab/rootfs-6818/usr/lib
