pro vis, file

  window, xs=512, ys=512
  data = load(file)

  plot, [-2,2], [-2, 2], /iso, /nodata, xTitle='x', yTitle='y'

  help, data.t
  help, data.x

  foreach t, data.t, i do $
     plots, data.x[*,i], data.y[*,i], psym=3

end
