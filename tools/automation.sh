#!/bin/bash

function start {
    echo "Bringing up virtual machine with vivado..."
    # prlctl start "Ubuntu Linux"
    echo "Connecting filesystems..."
    sshfs -o allow_other,defer_permissions,IdentityFile=~/.ssh/id_rsa kuky_nekoi@10.211.55.5:/ $(PWD)/mount/linux
    sshfs -o allow_other,defer_permissions,IdentityFile=~/.ssh/id_rsa parallella@192.168.2.2:/ $(PWD)/mount/parallella
    echo "Environment prepared."
}

function code_linux {
    code $(PWD)/mount/linux/home/kuky_nekoi/Memoria ;
}
function code_parallella {
    code $(PWD)/mount/parallella/home/parallella/Memoria ;
}

function stop {
    echo "Unmount filesystems..."
    umount $(PWD)/mount/linux
    umount $(PWD)/mount/parallella
    # echo "Bringing up virtual machine with vivado..."
    echo "Environment disconnected."
}

function run_vivado {
    ssh kuky_nekoi@10.211.55.5 -X ". ~/.profile; vivado"
}
function run_hls {
    ssh kuky_nekoi@10.211.55.5  -X ". ~/.profile; vivado_hls"
}

function sync_linux {
#    rm -rfv $(PWD)/sync/
    rsync -avz -e "ssh -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null" --progress kuky_nekoi@10.211.55.5:/home/kuky_nekoi/Memoria/ $(PWD)/sync/
}

function sync_parallella {
    rm -rfv $(PWD)/sync/
    rsync -avz -e "ssh -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null" --progress parallella@192.168.2.2:/home/parallella/Memoria/ $(PWD)/sync/
}


#using : after a switch variable means it requires some input (ie, t: requires something after t to validate while h requires nothing.
while getopts “:h?-:” OPTION
do
     case $OPTION in
         h)
            echo "AGG"
             usage
             exit 1
             ;;
         -)
            case ${OPTARG} in
                "start"*)    start
                    ;;
                "stop"*)    stop
                    ;;
                "vivado"*)    run_vivado
                    ;;
                "hls"*)    run_hls
                    ;;
                "sync-linux"*)    sync_linux
                    ;;
                "sync-parallella"*)    sync_parallella
                    ;;
                "code-linux"*)    code_linux
                    ;;
                "code-parallella"*)    code_parallella
                    ;;
                "code"*)    code_linux
                            code_parallella
                    ;;
            esac
     esac
done
