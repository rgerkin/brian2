{% extends 'common_group.cpp' %}
{% block maincode %}
    {# USES_VARIABLES { _synaptic_post, N_post } #}
	//// MAIN CODE ////////////
	{% set _target_var_array = get_array_name(_target_var) %}

	// Set all the target variable values to zero
	for (int _target_idx=0; _target_idx<N_post; _target_idx++)
	    {{_target_var_array}}[_target_idx] = 0.0;

	for(int _idx=0; _idx<_num_synaptic_post; _idx++)
	{
	    {{ super() }}
		{{_target_var_array}}[{{_synaptic_post}}[_idx]] += _synaptic_var;
	}
{% endblock %}
