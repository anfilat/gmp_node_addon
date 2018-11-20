{
  "targets": [
    {
      "target_name": "Gmp",
      "cxxflags": ['-fPIC'],
      "dependencies": ['libgmp'],
      "sources": [ "src/gmp_node_addon.cc" ],
      "conditions": [
         ['OS=="linux"', {
            "include_dirs": [
               "<!(node -e \"require('nan')\")",
               '<(module_root_dir)/src/gmp/include'
            ],
            "libraries": ['<(module_root_dir)/src/gmp/lib/libgmp.a']
         }]
      ]
    },
    {
      "target_name": "libgmp",
      "type": "none",
      "conditions": [
         ['OS=="linux"', {
            "actions": [{
               "action_name": 'build_gmp_lib',
               "inputs": [''],
               "outputs": [''],
               "action": ['sh', 'scripts/build.sh']
            }]
         }]
      ]
    },
    {
      "target_name": "action_after_build",
      "type": "none",
      "dependencies": [ "<(module_name)" ],
      "copies": [
        {
          "files": [ "<(PRODUCT_DIR)/<(module_name).node" ],
          "destination": "<(module_path)"
        }
      ]
    }
  ]
}
