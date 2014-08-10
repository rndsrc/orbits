; Copyright (C) 2014 Chi-kwan Chan
; Copyright (C) 2014 Steward Observatory
;
; This file is part of orbits.
;
; Orbits is free software: you can redistribute it and/or modify it
; under the terms of the GNU General Public License as published by
; the Free Software Foundation, either version 3 of the License, or
; (at your option) any later version.
;
; Orbits is distributed in the hope that it will be useful, but
; WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
; General Public License for more details.
;
; You should have received a copy of the GNU General Public License
; along with Orbits.  If not, see <http://www.gnu.org/licenses/>.

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
