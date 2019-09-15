#include <stdlib.h>
#include <guile/2.2/libguile.h>
#include <guile/gh.h>

#include "paste.h"

/* This function does the SCM packing and unpacking to convert
 * html-entities() into a Guile function */
SCM scm_paste (SCM scm_raw_text)
{
     SCM scm_out_text;
     char *raw_text;
     char *out_text;
     int length;

     /* Check that the input is a string */
     SCM_ASSERT (SCM_STRINGP(scm_raw_text), 
		 scm_raw_text, 
		 SCM_ARG1, 
		 "paste");
     
     /* Convert the Guile string to a C string */
     raw_text = gh_scm2newstr (scm_raw_text, &length);

     /* Call the C function */
     out_text = paste(raw_text);

     /* Convert the C function's output to an SCM */
     scm_out_text = scm_makfrom0str (out_text);

     free (out_text);
     return (scm_out_text);
}
 
