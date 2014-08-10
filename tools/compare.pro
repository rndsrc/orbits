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
