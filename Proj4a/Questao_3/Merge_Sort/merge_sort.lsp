%Douglas Benevides Almeida

(defun merge-sort (lista)
  (if (pequena lista)
      lista  ; 
      (merge-list
       (merge-sort (metade-esquerda lista))
       (merge-sort (metade-direita lista)))))

(defun pequena (lista)
  (or (null lista) (null (cdr lista))))

(defun metade-direita (lista)
  (last lista (ceiling (/ (length lista) 2))))

(defun metade-esquerda (lista)
  (ldiff lista (metade-direita lista)))

(defun merge-list (lista1 lista2)
  (merge 'list lista1 lista2 #'<))


(print (merge-sort '(3 4 8 0 6 7 4 2 1 9 4 5)))
