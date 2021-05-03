Ansible Galaxy is essentially a large public repository of Ansible roles. Roles ship with READMEs detailing the roles use and available variables. Galaxy contains a large number of roles that are constantly evolving and increasing.

Galaxy can use git to add other role sources, such as GitHub. You can initialize a new galaxy role using ansible-galaxy init, or you can install a role directly from the Ansible Galaxy role store by executing the command ansible-galaxy install <name of role>.

Some helpful ansible-galaxy commands you might use from time to time:

     Login to Ansible Galaxy:

	ansible-galaxy login


     List all installed roles:

	 ansible-galaxy list // displays a list of installed roles, with version numbers.


     Remove an installed Role:

         ansible-galaxy remove <role> // removes an installed role.


     Information abt role:

	 ansible-galaxy info <role-name> // provides a variety of information about Ansible Galaxy.

     Create ansible role:

	 ansible-galaxy init <role-name> // Used to create a role template suitable for submission to Ansible Galaxy.


     Install Role from galaxy:

         ansible-galaxy install username.role_name // To install the role

         ansible-galaxy install -r requirements.yml  // Install roles included in requirements.yml

Every ansible role we download using galaxy by default they are placed into the default directory /etc/ansible/roles.


Reference:

1. https://docs.ansible.com/ansible/2.7/reference_appendices/galaxy.html
