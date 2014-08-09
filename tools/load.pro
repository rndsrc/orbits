function load, name

  spawn, 'cat '+name+' | wc -l', m
  m  = long64(m)-1
  in = dblarr(7,m)
  n  = 0LL

  openr, lun, name, /get_lun
  readf, lun, n
  readf, lun, in
  close, lun & free_lun, lun

  in = reform(transpose(in), [n,m/n,7])
  rr = total((in[0,*,1:3] - in[1,*,1:3])^2, 3)
  uu = total(total(in[*,*,4:6]^2,3),1)
  E  = 0.5 * uu - 1.0 / sqrt(rr)
  d  = E / E[0] - 1

  return, {t:dindgen(m/n)/32,        m:in[*,*,0], $
           x:in[*,*,1], y:in[*,*,2], z:in[*,*,3], $
           u:in[*,*,4], v:in[*,*,5], w:in[*,*,6], $
           E:E,         d:d}
end
