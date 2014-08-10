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

function load, name

  spawn, 'cat '+name+'.dat | wc -l', m
  m  = long64(m)-1

  n  = 0LL
  in = dblarr(7,m)
  openr, lun, name+'.dat', /get_lun
  readf, lun, n
  readf, lun, in
  close, lun & free_lun, lun

  E  = dblarr(m/n)
  openr, lun, name+'.eng', /get_lun
  readf, lun, E
  close, lun & free_lun, lun

  in = reform(transpose(in), [n,m/n,7])
  return, {t:dindgen(m/n),           m:in[*,0,0], $
           x:in[*,*,1], y:in[*,*,2], z:in[*,*,3], $
           u:in[*,*,4], v:in[*,*,5], w:in[*,*,6], $
           E:E,         d:E / E[0] - 1}
end
