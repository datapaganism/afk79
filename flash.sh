#!/bin/bash

dfu-util -a 0 -d 0483:DF11 -s 0x8000000:leave -D ../../.build/afk79_default.bin 