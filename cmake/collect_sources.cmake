# function collects sources in global property GlobalSourceList
function(collect_sources)
    foreach(_source IN ITEMS ${ARGN})
        if (IS_ABSOLUTE "${_source}")
            set(source_abs "${_source}")
        else()
            get_filename_component(_source_abs "${_source}" ABSOLUTE)
        endif()
        set_property(GLOBAL APPEND PROPERTY GlobalSourceList "${_source_abs}")
    endforeach()
endfunction(collect_sources)

# conviniently return collected sources
function(get_collected_sources SOURCES)
    get_property(TEMPORARY GLOBAL PROPERTY GlobalSourceList)
    set(${SOURCES} ${TEMPORARY} PARENT_SCOPE)
endfunction(get_collected_sources)