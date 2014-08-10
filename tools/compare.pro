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
  plot, [min(Euler.t),max(Euler.t)], [1e-16, 1], /nodata, $
        /xStyle, /yStyle, /yLog, xTitle='time', yTitle=textoidl('|E/E_0-1|')

  oplot, Euler.t, abs(Euler.d), color=44  & print, 'Euler:', max(abs(Euler.d))
  oplot, DK.t,    abs(DK.d),    color=86  & print, 'DK:',    max(abs(DK.d))
  oplot, KD.t,    abs(KD.d),    color=128 & print, 'KD:',    max(abs(KD.d))
  oplot, DKD.t,   abs(DKD.d),   color=170 & print, 'DKD:',   max(abs(DKD.d))
  oplot, KDK.t,   abs(KDK.d),   color=212 & print, 'KDK:',   max(abs(KDK.d))
  oplot, ChinC.t, abs(ChinC.d), color=254 & print, 'ChinC:', max(abs(ChinC.d))

end
