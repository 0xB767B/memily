target remote 10.4.13.68:3333
monitor reset halt
load

define reset_halt
    monitor reset halt
end

define reboot
    monitor reset halt
    continue
end
