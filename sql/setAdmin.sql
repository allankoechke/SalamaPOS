UPDATE priviledges SET
        can_add_user            = TRUE,
        can_remove_user         = TRUE,
        can_add_product         = TRUE,
        can_remove_product	= TRUE,
        can_add_stock           = TRUE,
        can_remove_sales        = TRUE,
        can_remove_stock	= TRUE,
        can_backup              = TRUE
		 WHERE username = 'lalan';