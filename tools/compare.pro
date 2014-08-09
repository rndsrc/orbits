function load, name

  spawn, 'cat '+name+'.txt | wc -l', n
  n  = long64(n)
  in = dblarr(7,n)

  openr, lun, name+'.txt', /get_lun
  readf, lun, in
  close, lun & free_lun, lun

  in = transpose(in)

  rr = total(in[*,1:3]^2,2)
  uu = total(in[*,4:6]^2,2)
  E  = 0.5 * uu - 1.0 / sqrt(rr)
  d  = E / E[0] - 1

  return, {t:dindgen(n)/32,      m:in[*,0], $
           x:in[*,1], y:in[*,2], z:in[*,3], $
           u:in[*,4], v:in[*,5], w:in[*,6], $
           E:E,       d:d}
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
  plot, [0,100], [1e-10, 1], /nodata, /yLog

  oplot, Euler.t, abs(Euler.d), color=44  & print, 'Euler:', min(Euler.d), max(Euler.d)
  oplot, DK.t,    abs(DK.d),    color=86  & print, 'DK:',    min(DK.d),    max(DK.d)
  oplot, KD.t,    abs(KD.d),    color=128 & print, 'KD:',    min(KD.d),    max(KD.d)
  oplot, DKD.t,   abs(DKD.d),   color=170 & print, 'DKD:',   min(DKD.d),   max(DKD.d)
  oplot, KDK.t,   abs(KDK.d),   color=212 & print, 'KDK:',   min(KDK.d),   max(KDK.d)
  oplot, ChinC.t, abs(ChinC.d), color=254 & print, 'ChinC:', min(ChinC.d), max(ChinC.d)

end
