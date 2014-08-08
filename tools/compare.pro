function load, name

  in = dblarr(7,100)

  openr, lun, name+'.txt', /get_lun
  readf, lun, in
  close, lun & free_lun, lun

  in = transpose(in)

  rr = total(in[*,1:3]^2,2)
  uu = total(in[*,4:6]^2,2)

  return, {m:in[*,0], $
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
  t     = dindgen(100)+1

  plot, [1, 100], [-0.7, -0.2], /nodata
  oplot, t, Euler.E & print, min(Euler.E), max(Euler.E)
  oplot, t, DK.E    & print, min(DK.E),    max(DK.E)
  oplot, t, KD.E    & print, min(KD.E),    max(KD.E)
  oplot, t, DKD.E   & print, min(DKD.E),   max(DKD.E)
  oplot, t, KDK.E   & print, min(KDK.E),   max(KDK.E)

end
