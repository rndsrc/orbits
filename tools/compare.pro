function load, name

  spawn, 'cat '+name+'.txt | wc -l', m
  m  = long64(m)-1
  in = dblarr(7,m)
  n  = 0LL

  openr, lun, name+'.txt', /get_lun
  readf, lun, n
  readf, lun, in
  close, lun & free_lun, lun

  in = reform(transpose(in), [n,m/n,7])
  rr = total(in[*,*,1:3]^2,3)
  uu = total(in[*,*,4:6]^2,3)
  E  = 0.5 * uu - 1.0 / sqrt(rr)
  d  = E & for i = 0, n-1 do d[i,*] = E[i,*] / E[i,0] - 1

  return, {t:dindgen(m)/32,          m:in[*,*,0], $
           x:in[*,*,1], y:in[*,*,2], z:in[*,*,3], $
           u:in[*,*,4], v:in[*,*,5], w:in[*,*,6], $
           E:E,         d:d}
end

pro compare

  Euler = load('Euler')
  DK    = load('DK')
  KD    = load('KD')
  DKD   = load('DKD')
  KDK   = load('KDK')
  ChinC = load('ChinC')

  device, decompose=0
  loadct, 39
  plot, [0,100], [1e-15, 1], /nodata, /yLog

  oplot, Euler.t, abs(Euler.d[1,*]), color=44  & print, 'Euler:', max(abs(Euler.d[1,*]))
  oplot, DK.t,    abs(DK.d[1,*]),    color=86  & print, 'DK:',    max(abs(DK.d[1,*]))
  oplot, KD.t,    abs(KD.d[1,*]),    color=128 & print, 'KD:',    max(abs(KD.d[1,*]))
  oplot, DKD.t,   abs(DKD.d[1,*]),   color=170 & print, 'DKD:',   max(abs(DKD.d[1,*]))
  oplot, KDK.t,   abs(KDK.d[1,*]),   color=212 & print, 'KDK:',   max(abs(KDK.d[1,*]))
  oplot, ChinC.t, abs(ChinC.d[1,*]), color=254 & print, 'ChinC:', max(abs(ChinC.d[1,*]))

end
