pro vis, name, side=side, once=once

  if n_elements(name) eq 0 then name = 'ChinC'

  data = load(name)

  if keyword_set(side) then $
    side = side $
  else $
    side = 1.1 * max(abs([data.x, data.y]))

  window, xs=512, ys=512
  plot, [-side,side], [-side,side], /iso, /nodata, xTitle='x', yTitle='y'

  if keyword_set(once) then $
    plots, data.x, data.y, psym=3 $
  else $
    foreach t, data.t, i do $
      plots, data.x[*,i], data.y[*,i], psym=3

end
