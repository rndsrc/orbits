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

  return, {t:dindgen(n)/32,      m:in[*,0], $
           x:in[*,1], y:in[*,2], z:in[*,3], $
           u:in[*,4], v:in[*,5], w:in[*,6], $
           E:0.5 * uu - 1.0 / sqrt(rr)}
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
  plot, [0,100], [-0.7, 0], /nodata

  oplot, Euler.t, Euler.E, color=44  & print, 'Euler:', min(Euler.E), max(Euler.E)
  oplot, DK.t,    DK.E,    color=86  & print, 'DK:',    min(DK.E),    max(DK.E)
  oplot, KD.t,    KD.E,    color=128 & print, 'KD:',    min(KD.E),    max(KD.E)
  oplot, DKD.t,   DKD.E,   color=170 & print, 'DKD:',   min(DKD.E),   max(DKD.E)
  oplot, KDK.t,   KDK.E,   color=212 & print, 'KDK:',   min(KDK.E),   max(KDK.E)
  oplot, ChinC.t, ChinC.E, color=254 & print, 'ChinC:', min(ChinC.E), max(ChinC.E)

end
