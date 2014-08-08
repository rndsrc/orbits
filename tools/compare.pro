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

  plot, [0, 100], [-0.6, 0.2], /nodata
  oplot, Euler.E & print, min(Euler.E), max(Euler.E)
  oplot, DK.E    & print, min(DK.E),    max(DK.E)
  oplot, KD.E    & print, min(KD.E),    max(KD.E)
  oplot, DKD.E   & print, min(DKD.E),   max(DKD.E)
  oplot, KDK.E   & print, min(KDK.E),   max(KDK.E)

end
