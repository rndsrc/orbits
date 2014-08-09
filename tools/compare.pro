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
  rr = total((in[0,*,1:3] - in[1,*,1:3])^2, 3)
  uu = total(total(in[*,*,4:6]^2,3),1)
  E  = 0.5 * uu - 1.0 / sqrt(rr)
  d  = E / E[0] - 1

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

  window, xs=640, ys=480
  device, decompose=0
  loadct, 39
  plot, [0,100], [1e-16, 1], /nodata, /yLog, /yStyle, $
        xTitle='time (orbits)', yTitle=textoidl('|E/E_0-1|')

  oplot, Euler.t, abs(Euler.d), color=44  & print, 'Euler:', max(abs(Euler.d))
  oplot, DK.t,    abs(DK.d),    color=86  & print, 'DK:',    max(abs(DK.d))
  oplot, KD.t,    abs(KD.d),    color=128 & print, 'KD:',    max(abs(KD.d))
  oplot, DKD.t,   abs(DKD.d),   color=170 & print, 'DKD:',   max(abs(DKD.d))
  oplot, KDK.t,   abs(KDK.d),   color=212 & print, 'KDK:',   max(abs(KDK.d))
  oplot, ChinC.t, abs(ChinC.d), color=254 & print, 'ChinC:', max(abs(ChinC.d))

end
