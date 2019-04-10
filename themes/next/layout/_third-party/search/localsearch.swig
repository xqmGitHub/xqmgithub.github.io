{% if theme.local_search.enable %}
  <script type="text/javascript">
    // Popup Window;
    var isfetched = false;
    var isXml = true;
    // Search DB path;
    var search_path = "{{ config.search.path }}";
    if (search_path.length === 0) {
      search_path = "search.xml";
    } else if (/json$/i.test(search_path)) {
      isXml = false;
    }
    var path = "{{ config.root }}" + search_path;
    // monitor main search box;

  </script>
{% endif %}
