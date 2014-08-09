pro vis, name

  if n_elements(name) eq 0 then name = 'ChinC'

  window, xs=512, ys=512
  data = load(name)

  plot, [-2,2], [-2, 2], /iso, /nodata, xTitle='x', yTitle='y'
  foreach t, data.t, i do $
     plots, data.x[*,i], data.y[*,i], psym=3

end
