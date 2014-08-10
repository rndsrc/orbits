function load, name

  spawn, 'cat '+name+'.dat | wc -l', m
  m  = long64(m)-1

  n  = 0LL
  in = dblarr(7,m)
  openr, lun, name+'.dat', /get_lun
  readf, lun, n
  readf, lun, in
  close, lun & free_lun, lun

  E  = dblarr(m/n)
  openr, lun, name+'.eng', /get_lun
  readf, lun, E
  close, lun & free_lun, lun

  in = reform(transpose(in), [n,m/n,7])
  return, {t:dindgen(m/n),           m:in[*,0,0], $
           x:in[*,*,1], y:in[*,*,2], z:in[*,*,3], $
           u:in[*,*,4], v:in[*,*,5], w:in[*,*,6], $
           E:E,         d:E / E[0] - 1}
end
