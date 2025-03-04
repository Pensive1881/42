echo $(groups $FT_USER | cut -d: -f2 | tr ' ' ',')
